*This project has been created as part of the 42 curriculum by <agarcia2>.*

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

---<D-a>

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

- **Encrypted partitions** using LVM
- **Strong password policy** (expiration, complexity, history)
- **SSH configured on port 4242**
- **Root login via SSH disabled**
- **Firewall enabled (UFW)**
- **Sudo configured with logging and restrictions**
- **Custom monitoring script (`monitoring.sh`)**
- **No graphical interface installed**

---

## Instructions

### Requirements
- VirtualBox (or UTM if VirtualBox is unavailable)
- Debian Stable ISO
- Internet connection for initial setup

### Installation Steps (High Level)

1. Create a new virtual machine using Debian (stable).
2. Configure encrypted LVM partitions during installation.
3. Install only required system utilities (no GUI).
4. Configure:
   - SSH on port `4242`
   - UFW firewall
   - Strong password policy
   - Sudo rules
5. Create required users and groups.
6. Implement the `monitoring.sh` Bash script.
7. Ensure the monitoring script runs every 10 minutes using `cron`.
8. Generate the VM disk signature and save it in `signature.txt`.

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

## Resources

### Documentation & References
- Official Debian documentation
- Linux man pages
- Community forums and online articles
- Born2beRoot GitBook:  
  https://noreply.gitbook.io/born2beroot

### Use of AI

AI tools were used **only as learning assistance**, not for direct copying of solutions.

AI was used for:
- Clarifying Linux concepts (LVM, sudo, AppArmor, cron)
- Understanding error messages
- Reviewing Bash script logic
- Improving documentation clarity

No configuration files or scripts were blindly copied. All configurations were manually written, tested, and understood to comply with 42 rules and learning objectives.

---

## Notes

- Snapshots are **strictly forbidden**
- The virtual machine itself must **never** be pushed to the repository
- Only the `signature.txt` file is submitted
- Full understanding of the configuration is required for defense

---

## Status

✅ Mandatory part completed  
⬜ Bonus part (optional)

---

> Born to secure systems. No GUI. No shortcuts.
