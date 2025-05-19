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



    


