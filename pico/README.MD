## Dependancies

* Raspberry Pi Pico SDK
* CMake
* Make

## Installation

**Clone:**
```bash
    git clone https://github.com/JENSEN-IoT-Embedded-Project/security-application.git
```

**Change WiFi-credentials in main.c:**
```bash
vim src/main.c and change following:
#define WIFI_SSID "YOUR_WIFI_ID"
#define WIFI_PASS "YOUR_WIFI_PW"

```

**Change headerfile with MQTT-configuration:**
```bash
vim include/mqtt_config.h and change following:
#define _MQTT_BROKER_IP "YOUR_BROKER_IP"
#define _MQTT_PORT 1883 // standard port

```
