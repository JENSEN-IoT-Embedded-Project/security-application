import os 
import influxdb_client
import paho.mqtt.client as paho
from influxdb_client.client.write_api import SYNCHRONOUS
#creating a mqtt_client
mqtt_client = paho.Client(client_id="", userdata=None, protocol=paho.MQTTv5)
#creating a database object
bucket = "motion-data"
org = "school-database"
token = os.getenv("INFLUX_TOKEN")
url="http://localhost:8086/"

influx_client = influxdb_client.influxDBClient(
        url=url,
        token=token,
        org=org
)
#connect my zero to my home wifi
mqtt_client.connect("",1883)


mqtt_client.subscribe("sensors/motion",qos=1)
