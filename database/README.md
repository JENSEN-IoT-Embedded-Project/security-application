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

    


    


