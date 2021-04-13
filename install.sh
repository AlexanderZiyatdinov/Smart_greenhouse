docker run --init -d --name homeassistant --restart=unless-stopped -v /etc/localtime:/etc/localtime:ro -v $(pwd):/config --network=host  homeassistant/home-assistant:stable
