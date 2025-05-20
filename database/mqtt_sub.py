import os 
import influxdb_client
import json
import paho.mqtt.client as paho
from influxdb_client.client.write_api import SYNCHRONOUS
#creating influxdb object
bucket = "write yours"
org = "write yours"
token = os.getenv("INFLUX_TOKEN") # or just paste token
url="http://localhost:8086/"
influx_client = influxdb_client.InfluxDBClient(
        url=url,
        token=token,
        org=org
)
write_api = influx_client.write_api(write_options=SYNCHRONOUS)
#callback for writing data to terminal and to database
def on_message(client, userdata, message):
    #change if sending data in other format
    data = json.loads(message.payload.decode())
    p = (influxdb_client.Point("distance_measurement")
         .tag("device-id", data["device-id"])
         .field("distance", data["distance"]))
    write_api.write(bucket=bucket, org=org, record=p)
    print(data)

#creating a mqtt_client
mqtt_client = paho.Client(client_id="", userdata=None, protocol=paho.MQTTv5)

#connect my zero to my home wifi and liste to topic
mqtt_client.connect("write your borker ip",1883)
mqtt_client.subscribe("write your topic",qos=1)
mqtt_client.on_message = on_message
mqtt_client.loop_forever()
