docker run --init -d --name homeassistant --restart=unless-stopped -v /etc/localtime:/etc/localtime:ro -v $(pwd):/config -p "8123:8123"  homeassistant/home-assistant:stable
