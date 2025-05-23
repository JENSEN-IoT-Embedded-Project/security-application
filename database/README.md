# Influxdb2 Docker Setup
You can find the full installation guide and Influxdb documentation [HERE](https://docs.influxdata.com/influxdb/v2/)



## Quick docker Setup.
1. ***Create files to store user credentials for your database***

```bash
touch .env.influxdb2-admin-username
touch .env.influxdb2-admin-password
touch .env.influxdb2-admin-token
```

```bash
cat > .env.influxdb2-admin-username << EOF
change to your username
EOF
```

```bash
cat > .env.influxdb2-admin-password << EOF
change to your password
EOF
```

```bash
cat > .env.influxdb2-admin-token << EOF
change to your token
EOF
```
2. **Create and start the container**
```bash
docker compose up influxdb2
```
3. **Login to database**
    Press [login](http://localhost:8086/) to login to database and log in with your credentials added in .env files above.

## install influxdb2 CLI
proceed to this [guide](https://docs.influxdata.com/influxdb/v2/tools/influx-cli/) to install the influx-cli on your prefered operating system.

### Configurate influx CLI to your database running on docker

1. proceed to generate a token [api-token](http://localhost:8086/orgs/d4cf51eab34efaab/load-data/tokens)

2. proceed to get the name of your [organizaion](http://localhost:8086/orgs/d4cf51eab34efaab/about)

3. change required information and run this command.
```bash
      influx config create --config-name change-to-your-name \
  --host-url http://localhost:8086 \
  --org change-to-your-org-name \
  --token change-to-your-token \
  --active
```

# Create your first bucket
a bucket is a as it sounds a bucket where you can write or read data to and from.

easly described as a isolated enviroment where you store your collected data.
1. you can follow guide [here](https://docs.influxdata.com/influxdb/v2/admin/buckets/create-bucket/?t=influx+CLI)

or you can just paste this and change the name org and retention syntax.

```bash
influx bucket create \
  --name <bucket-name> \
  --org <org-name> \
  --retention <retention-period-duration>
```
2. now you should be able to see the bucket created [here](http://localhost:8086/orgs/d4cf51eab34efaab/load-data/buckets). the bucket is now ready for you to read or write data from or to it. 

# Python script for MQTT SUB & Influxdb client
```bash
pip3 install influxdb-client
```
```bash
pip3 install "paho-mqtt<2.0.0"
```
## in mqtt_sub.py
go into mqtt client and change 
**change**
```python3
bucket = "your-bucket"
org = "your org"
token = "your token" # or set env variable  os.getenv("INFLUX_TOKEN")
url="http://localhost:8086/"
```
```python3
mqtt_client.connect("write your borker ip",1883)
mqtt_client.subscribe("write your topic",qos=1)
```
## Test everything
**Start your docker container if not already started**
Go into your bucket [bucket](http://localhost:8086/orgs/d4cf51eab34efaab/load-data/buckets)

start your mqtt-broker

run:
```bash
   python3 mqtt_sub.py
```
Publish data to topic and it should now appear in your bucket make sure to send the data as following for it to be correct serialized for this example
```python3
 p = (influxdb_client.Point("distance_measurement")
         .tag("device-id", data["device-id"])
         .field("distance", data["distance"]))
```





 










    


