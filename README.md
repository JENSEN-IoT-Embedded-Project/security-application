# security-application
```mermaid
flowchart LR
    A[Pico W\n(Motionsensor)] -->|MQTT publish| B[MQTT Broker\n(Fog Raspberry Pi Zero)]
    B -->|MQTT subscribe| C[InfluxDB\n(Time-series DB)]
    C -->|HTTP GET request| D
```
