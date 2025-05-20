# security-application

```mermaid
flowchart LR
    A[Pico W med rörelsesensor] -->|MQTT publish| B[MQTT Broker<br>(Fog Raspberry Pi Zero)]
    B -->|MQTT subscribe| C[InfluxDB<br>(Time-series DB)]
    C -->|HTTP GET Request| D[Webbapp]
```
 
