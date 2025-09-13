# Computer Networks

## 🌐 1. **What is a Computer Network?**

A **computer network** is a system of **interconnected devices (nodes)** that can communicate and share resources (like files, internet, printers).

### 🔧 Devices involved:

- Computers
- Smartphones
- Servers
- Routers
- Switches
- Printers
- IoT Devices

### 🔄 Purpose:

- Share data (e.g., Google Drive)
- Access remote systems (e.g., SSH into a server)
- Communicate (e.g., WhatsApp)
- Share hardware (e.g., printer on WiFi)

### 🧠 Example:

Your home Wi-Fi connects your laptop, phone, and smart TV to the **router**, which connects them all to the **internet**. This is a **LAN (Local Area Network)**.

---

## 🌍 2. **Types of Networks**

### 🔹 a. **LAN (Local Area Network)**

- Covers a **small area**: home, office, school
- Devices are close together
- High speed (100 Mbps – 1 Gbps)
- Usually privately owned

**Example:**

Your school’s computer lab with 20 computers connected via Ethernet cables is a LAN.

---

### 🔹 b. **MAN (Metropolitan Area Network)**

- Covers a **city or campus** area (~5–50 km)
- Connects multiple LANs together
- Usually operated by ISPs, government, universities

**Example:**

A university with campuses in different parts of a city using fiber optic cables to interconnect them.

---

### 🔹 c. **WAN (Wide Area Network)**

- Spans **countries or continents**
- Uses routers and public infrastructure
- Slower than LANs but more scalable

**Example:**

The **Internet** is the largest WAN. Or a multinational company’s offices in different countries connected through leased lines.

---

### 🔹 d. **PAN (Personal Area Network)**

- Very short range (~10 meters)
- Designed for a single person’s devices

**Example:**

Your phone connected to your wireless earbuds and smartwatch via **Bluetooth**.

---

## 🔗 3. **Topologies** (Network Layouts)

Topology = **how devices are physically/logically connected**

---

### 🔸 a. **Bus Topology**

- All devices share a single communication line (backbone)
- Data is broadcast to all, only the intended receiver processes it

🟡 Example:

Old Ethernet networks using coaxial cable.

✅ Pros:

- Simple, cheap for small networks

❌ Cons:

- Data collisions
- One failure in backbone = total failure

---

### 🔸 b. **Star Topology**

- All devices are connected to a central **hub/switch**
- Most common in modern LANs

🟢 Example:

Home WiFi: All devices connect to your router (central point).

✅ Pros:

- Easy to manage
- Failure of one device doesn’t affect others

❌ Cons:

- Central hub failure = network failure

---

### 🔸 c. **Ring Topology**

- Each device connects to exactly two others, forming a ring
- Data travels in one direction (or two, in a dual ring)

🟠 Example:

Used in some older IBM networks (Token Ring)

✅ Pros:

- Predictable performance

❌ Cons:

- One broken link can take down the network (unless it’s a dual ring)

---

### 🔸 d. **Mesh Topology**

- Devices are interconnected with **multiple paths**
- High fault tolerance

🔵 Example:

Military networks or critical systems like blockchain or BGP routing between ISPs.

✅ Pros:

- Robust, reliable

❌ Cons:

- Very expensive
- Complex setup

---

### 🔸 e. **Hybrid Topology**

- Combines two or more topologies
- Very common in real-world enterprise setups

🟣 Example:

A company might use **Star topology** inside each office, and **Mesh** between branch offices for backup links.

✅ Pros:

- Scalable
- Customizable

❌ Cons:

- Complex to design and maintain

---

## 🛠️ 4. **Network Devices**

---

### 🔹 1. **Router**

- Connects **different networks** (e.g., LAN to Internet)
- Performs **routing** based on IP addresses
- Can assign IPs via DHCP, perform NAT

🧠 Example:

Your home **Wi-Fi router** connects your local devices to the **Internet (WAN)**.

---

### 🔹 2. **Switch**

- Connects devices **within the same network** (LAN)
- Uses **MAC addresses** to forward data to the correct device
- Reduces collisions vs a hub

🧠 Example:

In a corporate network, all employee computers connect to a switch.

---

### 🔹 3. **Hub** (Outdated)

- A **dumb switch**
- Broadcasts incoming data to **all devices**
- Causes traffic and collisions

🧠 Example:

Very rarely used now; mostly for learning labs or legacy networks.

---

### 🔹 4. **Bridge**

- Connects **two LAN segments**
- Filters traffic based on MAC address
- Useful for reducing traffic

🧠 Example:

Connecting a wired segment of a network to a wireless one.

---

### 🔹 5. **Modem**

- **Modulator + Demodulator**
- Converts **digital signals (computer)** into **analog (telephone line)** and vice versa

🧠 Example:

DSL/cable modem provided by your ISP.

---

### 🔹 6. **Repeater**

- Boosts and retransmits signals
- Used to extend physical range

🧠 Example:

WiFi repeater in a big house where signal from the main router doesn’t reach far rooms.

---

### 🔹 7. **Access Point**

- Extends **wireless** coverage
- Acts as a bridge between wireless clients and a wired LAN

🧠 Example:

WiFi access points installed in a university to provide full-campus coverage.

---

## ✅ Summary Table:

| Device | Layer | Function | Example |
| --- | --- | --- | --- |
| Router | 3 | Connects networks, routes packets | Home router |
| Switch | 2 | Connects devices in LAN via MAC | Office Ethernet switch |
| Hub | 1 | Broadcasts packets to all | Obsolete; used in labs |
| Bridge | 2 | Connects LAN segments | Wired-Wireless bridge |
| Modem | 1 | Digital ↔ Analog signal conversion | Cable/DSL modem |
| Repeater | 1 | Boosts signal | WiFi extender |
| Access Point | 2 | Wireless bridge to wired LAN | Uni WiFi access point |

# 🌐 **2. OSI Model (Open Systems Interconnection Model)**

The OSI model is a **conceptual framework** that standardizes how communication should happen between computers in a network.

It divides communication into **7 abstract layers**, each with **specific roles**, where **each layer serves the one above and is served by the one below**.

---

### 🧱 OSI Layers (Bottom to Top):

| Layer | Name | Unit of Data | Role |
| --- | --- | --- | --- |
| 7 | Application | Data | User interface, app protocols |
| 6 | Presentation | Data | Encoding, encryption |
| 5 | Session | Data | Connections, session handling |
| 4 | Transport | Segment | Reliable delivery |
| 3 | Network | Packet | Routing and IP addressing |
| 2 | Data Link | Frame | MAC addressing, framing |
| 1 | Physical | Bits | Cables, electrical signals |

---

## 🧩 **Layer 1: Physical Layer**

### 🔧 Responsibilities:

- Transmit **raw binary data** (0s and 1s) over a physical medium
- Defines **voltages, pin layouts, cable specs**, timing
- Deals with **modulation, signal strength, bit rate**

### 📦 Data Unit: **Bits**

### ⚙️ Real-World Examples:

- Ethernet cables (Cat5e, Cat6)
- Fiber optics
- Coaxial cables
- Electrical signals (voltage levels)
- Wireless signals (WiFi, radio)

### 🧠 Devices:

- **Cables**
- **Hubs**
- **Repeaters**
- **Network Interface Cards (NIC)** (partially)

### 🧪 Example:

When you type a message and hit send on WhatsApp, the binary bits are transmitted over your WiFi radio waves — that’s the physical layer at work.

---

## 🧩 **Layer 2: Data Link Layer**

### 🔧 Responsibilities:

- Converts raw bits to **frames**
- **Error detection** (using CRC)
- **MAC addressing** (unique hardware address)
- **Flow control** between two devices on the same link

Divided into 2 sublayers:

1. **LLC (Logical Link Control)** – error checking
2. **MAC (Media Access Control)** – media access, addressing

### 📦 Data Unit: **Frame**

### ⚙️ Protocols:

- **Ethernet (IEEE 802.3)**
- **WiFi (802.11)**
- **ARP** (Address Resolution Protocol)
- PPP (Point-to-Point Protocol)

### 🧠 Devices:

- **Switches**
- **NICs**
- Bridges

### 🧪 Example:

When your laptop sends a packet over WiFi, it attaches your MAC address and AP's MAC address using 802.11 framing.

---

## 🧩 **Layer 3: Network Layer**

### 🔧 Responsibilities:

- Responsible for **routing** packets from source to destination (possibly across networks)
- Handles **IP addressing**
- Deals with **packet fragmentation**

### 📦 Data Unit: **Packet**

### ⚙️ Protocols:

- **IPv4/IPv6**
- **ICMP** (used in ping/traceroute)
- **IPSec**
- Routing Protocols: **OSPF, BGP, RIP**

### 🧠 Devices:

- **Routers**
- **Layer 3 Switches**

### 🧪 Example:

When you ping `google.com`, an ICMP packet is sent across the internet using the IP address of Google.

---

## 🧩 **Layer 4: Transport Layer**

### 🔧 Responsibilities:

- Ensures **reliable or unreliable** data delivery
- Implements **flow control**, **error control**, and **congestion control**
- Breaks data into **segments** or datagrams

### 📦 Data Unit: **Segment** (TCP), **Datagram** (UDP)

### ⚙️ Protocols:

- **TCP** – reliable, connection-oriented (used by HTTP, FTP)
- **UDP** – fast, connectionless (used by DNS, VoIP, video streaming)
- **SCTP** – supports multistreaming and multihoming

### 🧠 Concepts:

- 3-Way Handshake (TCP)
- Acknowledgments
- Sliding Window Protocol
- Port numbers (e.g., 80 for HTTP, 443 for HTTPS)

### 🧠 Devices:

- **Host systems**
- **Firewalls**

### 🧪 Example:

When you load a webpage, your browser uses **TCP** to establish a connection with the server using a **3-way handshake**, ensuring all packets arrive in order.

---

## 🧩 **Layer 5: Session Layer**

### 🔧 Responsibilities:

- Establishes, maintains, and terminates **sessions**
- Supports **authentication**, **authorization**
- Handles **session checkpoints and recovery**

### 📦 Data Unit: **Data**

### ⚙️ Protocols & APIs:

- **NetBIOS**, **RPC** (Remote Procedure Call)
- **Sockets**, **WinSock**, **TLS sessions**

### 🧠 Devices:

- Software layer in endpoints (not physical)

### 🧪 Example:

Zoom uses session management to ensure that even if your network drops momentarily, your meeting session resumes when you reconnect.

---

## 🧩 **Layer 6: Presentation Layer**

### 🔧 Responsibilities:

- Data translation between app and network
- **Encryption/decryption**
- **Compression/decompression**
- Format conversion (JPEG ↔ Binary, etc.)

### 📦 Data Unit: **Data**

### ⚙️ Examples:

- **SSL/TLS** (technically at Layer 5/6 boundary)
- **MIME (email format)**
- **Codecs** (MP3, JPEG, MPEG)

### 🧠 Devices:

- Software level: Application processors, browsers

### 🧪 Example:

When you upload a JPEG image to a server, the presentation layer helps encode it, maybe compress it, and encrypt the connection (via SSL).

---

## 🧩 **Layer 7: Application Layer**

### 🔧 Responsibilities:

- Closest to the user
- Provides **interfaces and protocols** used by applications
- Interacts directly with software like browsers and email clients

### 📦 Data Unit: **Data**

### ⚙️ Protocols:

- **HTTP/HTTPS** – Web browsing
- **DNS** – Domain name resolution
- **FTP** – File transfers
- **SMTP, POP3, IMAP** – Email
- **DHCP** – Dynamic IP assignment

### 🧠 Devices:

- Software: Browsers, Email Clients, File Transfer Apps

### 🧪 Example:

When you type `openai.com` in your browser:

- Browser uses **HTTP**
- Requests **DNS resolution**
- Uses a **TCP session**
- Travels over **IP network**
- Goes through switch/router infrastructure
- Is transmitted via Ethernet/WiFi and fiber cables

---

---

## 1. **What is the TCP/IP Model?**

The **TCP/IP model** (also called the Internet Protocol Suite) is a **simplified, real-world protocol stack** used for internetworking, especially over the Internet. It was developed by the **Department of Defense (DoD)** in the 1970s and is **protocol-oriented**, unlike the OSI model which is purely theoretical and **layer-oriented**.

## 3. **TCP/IP Layers and Their Responsibilities**

---

### Layer 1: **Network Access Layer**

(Equivalent to OSI's Physical + Data Link)

**Responsibilities**:

- Physical transmission of data over the medium (electrical, optical, radio)
- Framing, MAC addressing, error detection on the link

**Protocols**:

- Ethernet (IEEE 802.3)
- Wi-Fi (IEEE 802.11)
- PPP (Point-to-Point Protocol)
- ARP (Address Resolution Protocol)

**Devices**:

- Network Interface Cards (NICs), switches, cables, wireless access points

**Real-world Example**:

Your laptop sends Ethernet frames with a MAC address over a CAT6 cable to a switch.

---

### Layer 2: **Internet Layer**

(Equivalent to OSI's Network Layer)

**Responsibilities**:

- Routing and forwarding of packets across multiple networks
- Logical addressing using IP addresses
- Fragmentation and reassembly

**Protocols**:

- IPv4
- IPv6
- ICMP (for error messaging, used in ping)
- IGMP (Multicast group management)

**Devices**:

- Routers, Layer 3 switches

**Real-world Example**:

When you ping a remote server, ICMP packets travel across the internet using IP addresses.

---

### Layer 3: **Transport Layer**

(Equivalent to OSI's Transport Layer)

**Responsibilities**:

- End-to-end communication between hosts
- Error checking, retransmissions (in case of TCP)
- Flow and congestion control
- Port addressing

**Protocols**:

- TCP (Transmission Control Protocol): reliable, connection-oriented
- UDP (User Datagram Protocol): fast, connectionless

**Devices**:

- End hosts (your computer, servers)

**Real-world Example**:

When you watch a YouTube video, TCP ensures that all video data arrives in the correct order; when using DNS, UDP is typically used for fast resolution.

---

### Layer 4: **Application Layer**

(Equivalent to OSI's Application + Presentation + Session)

**Responsibilities**:

- Provides network services to user applications
- Data formatting, compression, encryption (done here in TCP/IP)
- Session management (done implicitly)

**Protocols**:

- HTTP/HTTPS (Web browsing)
- FTP (File Transfer)
- SMTP, POP3, IMAP (Email)
- DNS (Domain resolution)
- DHCP (Dynamic IP configuration)
- SSH, Telnet (Remote access)

**Devices**:

- End-user applications: Browsers, Mail Clients, FTP Clients

**Real-world Example**:

Typing `https://openai.com` in your browser triggers DNS resolution via UDP, followed by an HTTPS connection via TCP, all implemented in the application layer.

---

## 4. **Encapsulation and Decapsulation**

This is the **core mechanism** by which data travels across the network.

### **Encapsulation**:

When data moves **down** the TCP/IP stack (from Application to Physical):

1. **Application Layer** adds protocol-specific headers (e.g., HTTP)
2. **Transport Layer** adds a TCP/UDP header with source/destination ports
3. **Internet Layer** adds an IP header with source/destination IP addresses
4. **Network Access Layer** adds a frame header with MAC addresses

Each layer **wraps** the data inside its own header. This process is called **encapsulation**.

### Example:

Sending "Hello" via HTTP:

- Application: HTTP data = "Hello"
- Transport: Add TCP header → TCP segment
- Internet: Add IP header → IP packet
- Network Access: Add Ethernet header → Ethernet frame

### **Decapsulation**:

When data arrives at the destination, the process is **reversed** as the data moves **up** the stack. Each layer **removes its header**, interprets the data, and passes it up.

This modular structure allows for:

- Independent development of protocols
- Debugging at specific layers
- Scalability and interoperability

## **What is IP Addressing?**

## 1. **What is IP Addressing?**

An **IP address** is a **logical address** assigned to each device on a network to uniquely identify it.

### Two types:

- **IPv4** (Internet Protocol version 4) – 32-bit, widely used
- **IPv6** (Internet Protocol version 6) – 128-bit, newer, for future scalability

---

## 2. **IPv4 Addressing**

### Format:

- **32 bits**, written as **4 octets** (8 bits each), separated by dots.
- Example: `192.168.1.1`

### Binary Form:

- `192.168.1.1` → `11000000.10101000.00000001.00000001`

### Range:

- Minimum: `0.0.0.0`
- Maximum: `255.255.255.255`

### Divided into **5 classes** (historically):

| Class | Starting Range | Purpose |
| --- | --- | --- |
| A | 0.0.0.0 – 127.255.255.255 | Large networks |
| B | 128.0.0.0 – 191.255.255.255 | Medium networks |
| C | 192.0.0.0 – 223.255.255.255 | Small networks |
| D | 224.0.0.0 – 239.255.255.255 | Multicasting |
| E | 240.0.0.0 – 255.255.255.255 | Research |

Modern networks use **CIDR** (Classless Inter-Domain Routing) instead of class-based addressing.

---

## 3. **IPv6 Addressing**

### Format:

- **128 bits**, written as **8 blocks** of 4 hex digits, separated by colons
- Example: `2001:0db8:85a3:0000:0000:8a2e:0370:7334`

### Shortening Rules:

- Consecutive zero blocks can be replaced with `::` (only once per address)
- Leading zeroes can be omitted

**Example**:

`2001:0db8:0000:0000:0000:ff00:0042:8329` → `2001:db8::ff00:42:8329`

### Benefits over IPv4:

- Vast address space (2^128 addresses)
- Built-in security (IPSec)
- Better multicast and mobility support
- No need for NAT in most cases

---

## 4. **Public vs Private IP Addresses**

### **Private IPs**:

Used **inside LANs**, not routable over the Internet. Defined by **RFC 1918**.

| Class | Private IP Range |
| --- | --- |
| A | 10.0.0.0 – 10.255.255.255 |
| B | 172.16.0.0 – 172.31.255.255 |
| C | 192.168.0.0 – 192.168.255.255 |

Used in:

- Home networks
- Corporate LANs
- Behind NAT routers

### **Public IPs**:

- Globally unique, routable on the internet
- Assigned by **IANA** and **ISPs**

**Example**:

Your phone’s IP on mobile data is likely a public IP.

---

## 5. **Subnetting**

**Subnetting** is the process of dividing a large network into **smaller subnetworks** to improve:

- Network organization
- Performance
- Security

### Key Terms:

- **Network ID**: Identifies the network (e.g., `192.168.1.0`)
- **Host ID**: Identifies a device within the network
- **Subnet Mask**: Distinguishes the network vs host part

### Example:

- IP: `192.168.1.10`
- Subnet Mask: `255.255.255.0` (or `/24`)
- Binary:
    - IP: `11000000.10101000.00000001.00001010`
    - Mask: `11111111.11111111.11111111.00000000`

Here, first 24 bits are **network**, last 8 are **host**.

---

## 6. **CIDR (Classless Inter-Domain Routing)** and Supernetting

CIDR allows using arbitrary-length subnet masks like `/18`, `/26`, etc., instead of fixed class A/B/C masks.

### CIDR Notation:

`192.168.1.0/24` → means 24 bits are for network, remaining 8 bits for hosts.

### Supernetting:

- Opposite of subnetting
- Combines multiple smaller networks into one larger network
- Used by ISPs to aggregate routes

### Example:

`192.168.0.0/24` + `192.168.1.0/24` → `192.168.0.0/23`

---

## 7. **Subnet Masks**

The **subnet mask** tells which portion of an IP is network and which is host.

### Examples:

| CIDR | Subnet Mask | Hosts per Subnet |
| --- | --- | --- |
| /24 | 255.255.255.0 | 254 |
| /26 | 255.255.255.192 | 62 |
| /30 | 255.255.255.252 | 2 |

**Formula**:

- Hosts per subnet = `2^(32 - subnet bits) - 2` (subtracting network & broadcast)

---

## 8. **Broadcast Address**

Each subnet has a **broadcast address**, which is used to send data to all devices in the subnet.

### How to Find:

- Invert all host bits to 1
- Example:
    - Subnet: `192.168.1.0/24`
    - Broadcast: `192.168.1.255`

Used in protocols like ARP, DHCP discovery.

---

## 9. **VLSM (Variable Length Subnet Masking)**

VLSM allows **using different subnet masks** in the same network to efficiently utilize IPs.

### Example:

- `/30` for point-to-point links (2 hosts)
- `/24` for large LANs (254 hosts)
- `/27` for medium-sized segments (30 hosts)

### Why VLSM is Important:

Without it, you waste IPs. With it, you can **tailor subnet sizes** to actual need.

---

## 10. **Binary Calculations for Subnetting**

You should be fluent in binary when subnetting:

- Convert IPs and masks to binary
- Use AND operation to find **Network ID**
- Use inverse mask to find **broadcast**

### Example:

Given:

- IP: `192.168.1.10`
- Mask: `/26` → `255.255.255.192` → `11000000`

**Step-by-step**:

1. IP in binary: `11000000.10101000.00000001.00001010`
2. Mask in binary: `11111111.11111111.11111111.11000000`
3. AND operation:
    
    → `11000000.10101000.00000001.00000000` → Network: `192.168.1.0`
    
4. Broadcast:
    - Invert host bits: `192.168.1.63`
5. Hosts = `2^6 - 2 = 62`

An **IP address** is a **logical address** assigned to each device on a network to uniquely identify it.

### Two types:

- **IPv4** (Internet Protocol version 4) – 32-bit, widely used
- **IPv6** (Internet Protocol version 6) – 128-bit, newer, for future scalability

---

## 2. **IPv4 Addressing**

### Format:

- **32 bits**, written as **4 octets** (8 bits each), separated by dots.
- Example: `192.168.1.1`

### Binary Form:

- `192.168.1.1` → `11000000.10101000.00000001.00000001`

### Range:

- Minimum: `0.0.0.0`
- Maximum: `255.255.255.255`

### Divided into **5 classes** (historically):

| Class | Starting Range | Purpose |
| --- | --- | --- |
| A | 0.0.0.0 – 127.255.255.255 | Large networks |
| B | 128.0.0.0 – 191.255.255.255 | Medium networks |
| C | 192.0.0.0 – 223.255.255.255 | Small networks |
| D | 224.0.0.0 – 239.255.255.255 | Multicasting |
| E | 240.0.0.0 – 255.255.255.255 | Research |

Modern networks use **CIDR** (Classless Inter-Domain Routing) instead of class-based addressing.

---

## 3. **IPv6 Addressing**

### Format:

- **128 bits**, written as **8 blocks** of 4 hex digits, separated by colons
- Example: `2001:0db8:85a3:0000:0000:8a2e:0370:7334`

### Shortening Rules:

- Consecutive zero blocks can be replaced with `::` (only once per address)
- Leading zeroes can be omitted

**Example**:

`2001:0db8:0000:0000:0000:ff00:0042:8329` → `2001:db8::ff00:42:8329`

### Benefits over IPv4:

- Vast address space (2^128 addresses)
- Built-in security (IPSec)
- Better multicast and mobility support
- No need for NAT in most cases

---

## 4. **Public vs Private IP Addresses**

### **Private IPs**:

Used **inside LANs**, not routable over the Internet. Defined by **RFC 1918**.

| Class | Private IP Range |
| --- | --- |
| A | 10.0.0.0 – 10.255.255.255 |
| B | 172.16.0.0 – 172.31.255.255 |
| C | 192.168.0.0 – 192.168.255.255 |

Used in:

- Home networks
- Corporate LANs
- Behind NAT routers

### **Public IPs**:

- Globally unique, routable on the internet
- Assigned by **IANA** and **ISPs**

**Example**:

Your phone’s IP on mobile data is likely a public IP.

---

## 5. **Subnetting**

**Subnetting** is the process of dividing a large network into **smaller subnetworks** to improve:

- Network organization
- Performance
- Security

### Key Terms:

- **Network ID**: Identifies the network (e.g., `192.168.1.0`)
- **Host ID**: Identifies a device within the network
- **Subnet Mask**: Distinguishes the network vs host part

### Example:

- IP: `192.168.1.10`
- Subnet Mask: `255.255.255.0` (or `/24`)
- Binary:
    - IP: `11000000.10101000.00000001.00001010`
    - Mask: `11111111.11111111.11111111.00000000`

Here, first 24 bits are **network**, last 8 are **host**.

---

## 6. **CIDR (Classless Inter-Domain Routing)** and Supernetting

CIDR allows using arbitrary-length subnet masks like `/18`, `/26`, etc., instead of fixed class A/B/C masks.

### CIDR Notation:

`192.168.1.0/24` → means 24 bits are for network, remaining 8 bits for hosts.

### Supernetting:

- Opposite of subnetting
- Combines multiple smaller networks into one larger network
- Used by ISPs to aggregate routes

### Example:

`192.168.0.0/24` + `192.168.1.0/24` → `192.168.0.0/23`

---

## 7. **Subnet Masks**

The **subnet mask** tells which portion of an IP is network and which is host.

### Examples:

| CIDR | Subnet Mask | Hosts per Subnet |
| --- | --- | --- |
| /24 | 255.255.255.0 | 254 |
| /26 | 255.255.255.192 | 62 |
| /30 | 255.255.255.252 | 2 |

**Formula**:

- Hosts per subnet = `2^(32 - subnet bits) - 2` (subtracting network & broadcast)

---

## 8. **Broadcast Address**

Each subnet has a **broadcast address**, which is used to send data to all devices in the subnet.

### How to Find:

- Invert all host bits to 1
- Example:
    - Subnet: `192.168.1.0/24`
    - Broadcast: `192.168.1.255`

Used in protocols like ARP, DHCP discovery.

---

## 9. **VLSM (Variable Length Subnet Masking)**

VLSM allows **using different subnet masks** in the same network to efficiently utilize IPs.

### Example:

- `/30` for point-to-point links (2 hosts)
- `/24` for large LANs (254 hosts)
- `/27` for medium-sized segments (30 hosts)

### Why VLSM is Important:

Without it, you waste IPs. With it, you can **tailor subnet sizes** to actual need.

---

## 10. **Binary Calculations for Subnetting**

You should be fluent in binary when subnetting:

- Convert IPs and masks to binary
- Use AND operation to find **Network ID**
- Use inverse mask to find **broadcast**

### Example:

Given:

- IP: `192.168.1.10`
- Mask: `/26` → `255.255.255.192` → `11000000`

**Step-by-step**:

1. IP in binary: `11000000.10101000.00000001.00001010`
2. Mask in binary: `11111111.11111111.11111111.11000000`
3. AND operation:
    
    → `11000000.10101000.00000001.00000000` → Network: `192.168.1.0`
    
4. Broadcast:
    - Invert host bits: `192.168.1.63`
5. Hosts = `2^6 - 2 = 62`

# 5. **Routing in Computer Networks**

## 🧭 What is Routing?

**Routing** is the process of selecting a path for traffic in a network or across multiple networks. It determines how **data packets** travel from the **source to the destination** through a series of routers.

Every router makes a decision based on a **routing table** and **routing protocols** to determine the next best hop for the packet.

---

## 🔁 Static vs Dynamic Routing

### 📌 Static Routing

**Definition**: Routing entries are manually configured by a network administrator.

### ✅ Advantages:

- Predictable (admin-controlled)
- Less overhead (no protocol traffic)
- More secure (no dynamic updates)

### ❌ Disadvantages:

- No automatic adaptation to network failures
- Not scalable for large or frequently changing networks

### 🧪 Example:

```bash
Router(config)# ip route 192.168.2.0 255.255.255.0 10.0.0.2
```

This tells the router: "To reach 192.168.2.0, go via 10.0.0.2".

---

### 📌 Dynamic Routing

**Definition**: Routers communicate with each other using routing protocols to automatically learn and update routes.

### ✅ Advantages:

- Automatically adapts to network changes (link failures, new paths)
- Scalable and efficient for large networks

### ❌ Disadvantages:

- Consumes CPU, memory, and bandwidth
- More complex to manage

### 🧪 Example:

A router running OSPF or RIP will automatically learn routes from neighboring routers.

---

## 🧭 Distance Vector vs Link State Routing

These are two **routing algorithm types** used by dynamic protocols.

---

### 📌 Distance Vector Routing

**Principle**: Routers exchange **entire routing tables** with directly connected neighbors at regular intervals.

- Decisions are based on the **distance (metric)** to each destination.
- Common metric: **hop count**

### 📌 Protocols:

- RIP (Routing Information Protocol)
- IGRP (Interior Gateway Routing Protocol)

### 🔁 Characteristics:

- Slower convergence
- Prone to routing loops (solved by split horizon, poison reverse)
- Simpler and lower resource usage

### 🔄 Example:

Router A tells Router B: "I can reach 10.0.0.0 in 2 hops".

---

### 📌 Link State Routing

**Principle**: Routers share **information about their directly connected links (states)**, not entire routing tables.

- Each router builds a complete **map (topology)** of the network and computes the best path using algorithms like **Dijkstra's shortest path**.

### 📌 Protocols:

- OSPF (Open Shortest Path First)
- IS-IS

### 🔁 Characteristics:

- Faster convergence
- Scalable and accurate
- Requires more memory and CPU

### 🔄 Example:

OSPF router floods link-state advertisements (LSAs) throughout the area.

---

## 📦 Routing Protocols

### 1. **RIP (Routing Information Protocol)**

- **Type**: Distance Vector
- **Max hops**: 15 (16 = unreachable)
- **Metric**: Hop count
- **Updates**: Every 30 seconds
- **Use case**: Small networks
- **Versions**: RIP v1 (classful), RIP v2 (classless)

### 2. **OSPF (Open Shortest Path First)**

- **Type**: Link State
- **Metric**: Cost (based on bandwidth)
- **Algorithm**: Dijkstra's SPF
- **Convergence**: Fast
- **Use case**: Medium to large enterprise networks
- **Supports VLSM and CIDR**: Yes
- **Organized in**: Areas (to reduce LSA flooding)

### 3. **EIGRP (Enhanced Interior Gateway Routing Protocol)**

- **Type**: Hybrid (Distance vector + Link state features)
- **Proprietary**: Cisco (until it became open-standard)
- **Metric**: Bandwidth, delay, reliability
- **Convergence**: Very fast
- **Uses DUAL algorithm**: Diffusing Update Algorithm

### 4. **BGP (Border Gateway Protocol)**

- **Type**: Path Vector
- **Used for**: Inter-AS (Autonomous System) routing on the Internet
- **Metric**: Policies, path attributes, AS-path
- **Very scalable**: Backbone of the Internet
- **External Gateway Protocol (EGP)**: The only widely used EGP
- **BGP routers** exchange entire path information (list of AS numbers)

---

## 📋 Routing Table

A **routing table** is a database stored in the router’s memory. It contains:

- Destination network
- Subnet mask
- Next-hop IP address
- Outgoing interface
- Metric

### Example Routing Table Entry:

```
nginx
CopyEdit
Destination    Subnet Mask     Next Hop     Interface   Metric
192.168.2.0    255.255.255.0   10.0.0.2     eth0        1

```

### Table Types:

- **Directly Connected Routes**
- **Static Routes**
- **Dynamic Routes** (learned via protocols)

---

## 📦 Route Aggregation (Supernetting)

**Route aggregation** is the process of combining multiple smaller subnets into a single route to reduce routing table size.

### 🧪 Example:

Instead of advertising:

```
192.168.0.0/24
192.168.1.0/24
192.168.2.0/24
```

Advertise:

```
192.168.0.0/22
```

This reduces the number of entries in the routing table and increases efficiency.

# **6. Switching in Computer Networks**

## 🧠 What is Switching?

**Switching** refers to the process of forwarding data frames between devices in a network using **hardware-based** logic and **MAC addresses**. The device responsible for switching is a **network switch** (not a hub or router).

---

## 📘 1. MAC Table / Forwarding Table (a.k.a. CAM Table)

### 💡 Definition:

A **MAC Table** is a lookup table maintained by a **switch** that maps each **MAC address** to the corresponding **switch port** it was last seen on.

### 🧪 Example:

| MAC Address | Port |
| --- | --- |
| 00:0a:95:9d:68:16 | Fa0/1 |
| 00:0a:95:9d:68:17 | Fa0/2 |

### 🔄 How It Works:

1. When a frame arrives, the switch **learns** the source MAC and updates the table.
2. To forward a frame:
    - If destination MAC is known → forward to that port.
    - If not → **flood** the frame to all ports **except the one it came from**.

### 🔁 Table Aging:

- Entries time out if not used for a certain duration (default is ~5 minutes).

---

## ⚡ 2. Switching Techniques

### 🔹 **Store and Forward**

- Entire frame is received → switch checks for errors using **CRC** → then forwards.
- **Accurate** but **slower** due to full-frame buffering.
- Used in modern Ethernet switches for **error detection**.

### 🔹 **Cut-through Switching**

- Switch starts forwarding **as soon as destination MAC** is read.
- **Faster** than store-and-forward.
- **No error checking** (could forward corrupted frames).
- Useful in **low-latency** environments (e.g., high-frequency trading).

### 🔹 **Fragment-free Switching** (Hybrid):

- Switch waits for **first 64 bytes** (most collisions happen early) → then forwards.
- Balances speed and reliability.

---

## 🌐 3. VLANs and Trunking

### 🔸 What is a VLAN?

**VLAN (Virtual LAN)** allows logically segmenting a physical switch into **multiple broadcast domains**.

- Devices on same VLAN behave like they are on the same switch, **even if physically apart**.
- Each VLAN acts as a **separate Layer 2 network**.

### 🧪 Example:

- VLAN 10 → HR department
- VLAN 20 → Finance
- VLAN 30 → Engineering

Even if connected to the same switch, devices in VLAN 10 **cannot communicate** with VLAN 20 without a **Layer 3 device (router or L3 switch).**

---

### 🔹 Trunking and 802.1Q

To send multiple VLAN traffic over a single cable (like between switches), we use **trunk links**.

### 📌 IEEE 802.1Q (Dot1Q):

- Industry standard VLAN tagging method
- Adds a **4-byte VLAN tag** inside Ethernet frame
- Identifies which VLAN the frame belongs to

### 🧪 Example:

A trunk between Switch A and Switch B carries traffic from VLANs 10, 20, and 30 using 802.1Q tags.

---

## 🌲 4. Spanning Tree Protocol (STP)

### ❓ Why STP?

**Switches flood** unknown frames → if loops exist, frames loop **forever** → leads to **broadcast storms** and network **meltdown**.

**Spanning Tree Protocol (STP)** prevents this by:

- **Detecting loops**
- **Blocking** redundant paths while maintaining redundancy

---

### 📌 How STP Works:

1. **Elect a Root Bridge** (lowest Bridge ID)
2. Each switch chooses a **shortest path to root**
3. Redundant links are **put into blocking state**

### 💡 STP States:

- **Blocking**: Doesn't forward frames
- **Listening**: Preparing to participate
- **Learning**: Builds MAC table
- **Forwarding**: Actively forwarding traffic
- **Disabled**: Admin down

### ⏱️ Convergence Time:

Classic STP is **slow** (~30–50 seconds).

Modern variants like **RSTP (802.1w)** and **MSTP** are faster.

---

## 🌍 5. ARP and Proxy ARP

### 🔁 ARP (Address Resolution Protocol)

Used to resolve **IP address → MAC address** in a local subnet.

### 🔄 How ARP Works:

1. Device A wants to send to IP 192.168.1.5
2. Checks ARP cache → if not found:
3. Broadcasts: “Who has 192.168.1.5?”
4. Device B replies with its MAC address.
5. A sends the frame to that MAC address.

### 🧪 ARP Cache Example:

```
192.168.1.5 → 00:0a:95:9d:68:16
```

---

### 🌐 Proxy ARP

A router answers ARP requests on **behalf of another host**.

### 📌 When is it used?

- When devices are on **different subnets** but **don’t know** that.
- Used in legacy networks or special cases like NAT and VPNs.

### 🧪 Example:

Device A (192.168.1.5/24) tries to ARP for 192.168.2.1 (not local). The **router responds with its own MAC**, pretending to be 192.168.2.1.

# **7. Transport Layer – Deep Dive**

---

## 🚪 What is the Transport Layer?

The **Transport Layer** is responsible for **end-to-end communication** between devices across a network. It provides services such as:

- **Segmentation** of data
- **Reliable delivery** (TCP)
- **Flow and error control**
- **Multiplexing** (port numbers)

It sits between the **Network Layer (IP)** and the **Application Layer (HTTP, FTP, etc.)**.

---

## ⚙️ Protocols: **TCP and UDP**

---

## 🧱 **TCP (Transmission Control Protocol)**

TCP is a **connection-oriented**, **reliable**, and **ordered** protocol. It’s used when **accuracy and reliability** are more important than speed.

---

### 🔗 1. TCP 3-Way Handshake

Used to **establish a reliable connection** between a client and server.

### 🧪 Steps:

1. **SYN**: Client sends a TCP packet with SYN flag set (wants to start a connection).
2. **SYN-ACK**: Server responds with SYN and ACK (acknowledges and wants to start too).
3. **ACK**: Client sends ACK to confirm.

Only then the connection is considered **established**.

```
arduino
CopyEdit
Client → SYN → Server
Client ← SYN-ACK ← Server
Client → ACK → Server

```

---

### 📉 2. Congestion Control

TCP prevents **network congestion** using smart algorithms:

### a. **Slow Start**

- Starts with a small **congestion window (cwnd)**.
- Grows **exponentially** (doubling) each RTT until threshold.

### b. **Congestion Avoidance**

- After reaching the threshold, grows **linearly**.

### c. **AIMD (Additive Increase, Multiplicative Decrease)**

- On congestion (e.g., packet loss), cwnd is **halved** (multiplicative decrease).
- Then grows linearly (additive increase).

### d. **Fast Retransmit & Fast Recovery**

- If 3 duplicate ACKs are received, assume packet loss → **retransmit immediately**.

---

### 🪟 3. TCP Windowing (Sliding Window)

TCP uses a **Sliding Window Protocol** for **flow control**.

### 🎯 Goal:

Ensure the **sender doesn't overwhelm** the receiver.

### 🧪 Example:

- Receiver advertises `window size = 5`
- Sender can send **5 segments** without waiting for ACKs.

As ACKs are received, the window "slides" forward.

---

### 🔄 4. Acknowledgements

- TCP numbers each byte in a stream (using **sequence numbers**).
- Receiver sends **ACKs** with next expected byte number.
- If ACK is missing → **timeout or duplicate ACKs** → trigger retransmission.

---

### ⚙️ TCP Header Format

Contains fields like:

- **Source Port, Destination Port**
- **Sequence Number, Acknowledgment Number**
- **Flags**: SYN, ACK, FIN, RST
- **Window Size**
- **Checksum** for error detection

---

## 📦 **UDP (User Datagram Protocol)**

UDP is a **connectionless**, **unreliable**, and **faster** protocol. It doesn’t guarantee delivery, order, or error correction.

### 🔹 Key Features:

- No connection setup (low latency)
- No retransmissions
- Minimal overhead

### 🔹 Use Cases:

- Real-time applications: **VoIP, Online Gaming, Streaming**
- DNS, DHCP, SNMP

---

### 🔍 UDP Datagram Structure

| Field | Description |
| --- | --- |
| Source Port | Port of sender |
| Destination Port | Port of receiver |
| Length | Length of datagram |
| Checksum | Optional error check |
| Data | Application payload |

---

## 🔁 **TCP vs UDP – Comparison**

| Feature | TCP | UDP |
| --- | --- | --- |
| Connection | Connection-oriented | Connectionless |
| Reliability | Reliable (ACKs, retransmit) | Unreliable |
| Ordering | Guaranteed order | No ordering |
| Speed | Slower (handshake + overhead) | Faster (low overhead) |
| Header Size | 20 bytes (min) | 8 bytes |
| Use Cases | Web, Email, FTP | Video, DNS, Gaming |

---

## 🧠 Flow Control (in TCP)

### Sliding Window Protocol

Used to manage the **rate of data** sent by the sender to ensure the receiver can handle it.

- Receiver advertises `window size` in ACK
- Sender limits the amount of unacknowledged data in flight to that size

---

## 🛡️ Error Control (in TCP)

TCP uses multiple mechanisms to detect and correct errors:

1. **Checksum**: Detects errors in each segment.
2. **Acknowledgements (ACKs)**: Ensures packets are received.
3. **Timeouts**: Resend if ACK not received.
4. **Duplicate ACKs**: Fast retransmit.