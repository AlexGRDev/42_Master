*This project has been created as part of the 42 curriculum by agarcia2.*

# Born2beRoot

## Description

**Born2beRoot** is a system administration project from the 42 curriculum focused on introducing virtualization, Linux system setup, and basic server security concepts.

The goal of this project is to configure a secure Linux server inside a virtual machine by following strict rules related to partitioning, user management, firewall configuration, SSH security, password policies, and service monitoring.

This project provides hands-on experience with:
- Virtual machines
- Linux system administration
- Security hardening
- Bash scripting
- Understanding how a server works internally

No graphical interface is used. Everything is configured through the terminal to simulate a real server environment.

---

## Project Description & Technical Choices

### Operating System Choice

**Debian (stable)** was chosen for this project.

**Pros:**
- Very stable and reliable
- Large community and extensive documentation
- Recommended by 42 for beginners in system administration
- Uses AppArmor by default (simpler to manage than SELinux)

**Cons:**
- Slightly older packages compared to other distributions

**Why not Rocky Linux?**
- More complex setup
- SELinux configuration is stricter and harder for beginners
- Less beginner-friendly for a first server project

---

### Debian vs Rocky Linux

| Debian | Rocky Linux |
|------|------------|
| Beginner-friendly | Enterprise-oriented |
| AppArmor | SELinux |
| Easier setup | More complex security configuration |
| Recommended for newcomers | Requires deeper sysadmin knowledge |

---

### AppArmor vs SELinux

| AppArmor | SELinux |
|--------|---------|
| Profile-based | Policy-based |
| Easier to understand | More powerful but complex |
| Enabled by default on Debian | Default on Rocky |
| Good for learning | Used heavily in enterprise systems |

---

### UFW vs firewalld

| UFW | firewalld |
|----|-----------|
| Simple and readable | More complex |
| Ideal for small servers | Enterprise-focused |
| Used with Debian | Used with Rocky |
| Easy rule management | Zone-based system |

---

### VirtualBox vs UTM

| VirtualBox | UTM |
|-----------|-----|
| Cross-platform | Mainly for macOS (Apple Silicon) |
| Widely used | Simpler UI |
| Recommended by 42 | Alternative if VirtualBox is unavailable |

---

### Main Design Choices

- **Encrypted partitions** using LUKS + LVM, with the bonus layout (separate `/boot`, `/`, swap, `/home`, `/var`, `/srv`, `/tmp`, `/var/log`)
- **Strong password policy** (expiration, complexity, history)
- **SSH configured on port 4242**
- **Root login via SSH disabled**
- **Firewall enabled (UFW)**, only port 4242 (plus 80/tcp for the bonus WordPress site)
- **Sudo configured with logging and restrictions**
- **Custom monitoring script (`monitoring.sh`)**
- **No graphical interface installed**
- **Bonus services**: WordPress (lighttpd + MariaDB + PHP) and PostgreSQL

---

## Instructions

### Requirements
- VirtualBox (or UTM if VirtualBox is unavailable)
- Debian stable netinst ISO

### Installation Steps (High Level)

1. Create a virtual machine (VirtualBox) and attach the Debian stable netinst ISO.
2. Install Debian using a `preseed.cfg` answer file so the install is unattended and reproducible: locale/keyboard, hostname `<login>42`, user account, and a custom `partman-auto/expert_recipe` that builds an encrypted (LUKS) LVM volume group with separate logical volumes for `/`, swap, `/home`, `/var`, `/srv`, `/tmp` and `/var/log`, plus an unencrypted `/boot`. Only the `standard` task and `ssh-server` are selected — no desktop task, so no graphical server is ever installed.
3. After first boot, harden the system over SSH/console:
   - Hostname, `user42`/`sudo` groups for the login user
   - `/etc/login.defs` + `libpam-pwquality` for the password policy
   - `/etc/sudoers.d/` drop-in for the strict sudo rules
   - `sshd_config`: `Port 4242`, `PermitRootLogin no`
   - `ufw`: default deny incoming, allow only `4242/tcp` (and `80/tcp` for the bonus)
   - Confirm AppArmor is enabled and enforcing at boot
4. Deploy `monitoring.sh` via `/etc/cron.d/` (`@reboot` + `*/10 * * * *`).
5. Change every account's password once more after all configuration files are in place, so the final passwords are the ones actually protected by the policy.
6. Shut the VM down (no snapshots, ever) and generate `signature.txt` from the `.vhd`/`.vdi` file.

---

## Monitoring Script

The `monitoring.sh` script displays the following information every 10 minutes using `wall`:

- OS architecture and kernel version
- Physical and virtual CPU count
- RAM usage
- Disk usage
- CPU load
- Last reboot time
- LVM status
- Active TCP connections
- Logged-in users
- Network IP and MAC address
- Number of sudo commands executed

The script runs automatically at startup via `cron`.

---

## Bonus Part

The bonus part was only pursued once every mandatory check passed.

### Partition layout

The custom `partman-auto/expert_recipe` used at install time produces the layout requested by the subject:

```
NAME                    MOUNTPOINTS
sda
├─sda1                  /boot
├─sda2
└─sda5
  └─sda5_crypt
    ├─debian--vg-root   /
    ├─debian--vg-swap   [SWAP]
    ├─debian--vg-home   /home
    ├─debian--vg-var    /var
    ├─debian--vg-srv    /srv
    ├─debian--vg-tmp    /tmp
    └─debian--vg-varlog /var/log
```

### WordPress (lighttpd + MariaDB + PHP)

A functional WordPress site is deployed at the server root, served by **lighttpd** with **PHP-FPM** (`15-fastcgi-php-fpm.conf`), backed by a dedicated **MariaDB** database and least-privilege DB user. The install wizard was completed via WordPress's own `wp-admin/install.php` endpoint (no third-party installer tool was introduced). Port `80/tcp` was opened in UFW for this service.

### Extra service: PostgreSQL

The second bonus service is **PostgreSQL 17**. Reasoning: it is a completely different relational engine from MariaDB (different process model, WAL-based replication story, stricter standards compliance), so running it alongside WordPress's MySQL-family database demonstrates managing more than one database engine on the same host rather than just repeating the same stack. It is intentionally **not** exposed outside the machine — it listens only on `127.0.0.1`/`::1`, which is the secure default for a database that has no need to be reached from outside the VM; no extra UFW rule was opened for it. A demo database/table was created to confirm it is genuinely running and usable.

---

## Resources

### Documentation & References
- Official Debian documentation
- Debian Installer preseed documentation (`partman-auto`, `partman-crypto`)
- Linux man pages: `sudo`, `pam_pwquality`, `ufw`, `cron`
- WordPress and PostgreSQL official documentation
- Community forums and online articles
- Born2beRoot GitBook:  
  https://noreply.gitbook.io/born2beroot

### Use of AI

Honesty note, per the subject's AI Instructions chapter: this deliverable was built with **extensive** AI assistance (Claude), at the student's explicit request, rather than as incidental help on a self-driven build. Concretely, Claude:

- Wrote the `preseed.cfg` used for the unattended Debian install, including the custom encrypted-LVM `partman-auto/expert_recipe`.
- Drove the VirtualBox VM directly (`VBoxManage`: screenshots, keystroke injection, NAT port-forwarding) to get through the installer, unlock LUKS at boot, and log in.
- Applied all mandatory hardening over SSH/console: users/groups, `login.defs` + `pam_pwquality`, `sudoers.d`, `sshd_config`, `ufw`, AppArmor verification.
- Wrote `monitoring.sh` and its cron schedule.
- Installed and configured both bonus services (WordPress stack, PostgreSQL) and generated `signature.txt`.

**What this means for the defense**: the subject is explicit that AI is not available during the exam and that the evaluator will ask about *why* things are configured this way (differences between `aptitude`/`apt`, what SELinux/AppArmor is, how `monitoring.sh` and the sudo logging work, etc.). Because the heavy lifting here was automated, the student's own next step before defending this project is to actually read through every file this produced (`preseed.cfg`, the sudoers drop-in, `sshd_config`, `monitoring.sh`, the PAM config) and be able to explain each line unaided — the working VM is not, by itself, proof of understanding.

---

## Notes

- Snapshots are **strictly forbidden**
- The virtual machine itself must **never** be pushed to the repository
- Only the `signature.txt` file is submitted
- Full understanding of the configuration is required for defense

---

## Status

✅ Mandatory part completed  
✅ Bonus part completed (partition layout, WordPress, PostgreSQL)

---

> Born to secure systems. No GUI. No shortcuts.
