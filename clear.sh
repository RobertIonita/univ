cleanUp() {

    for i in $(ls $1 | grep '.dSYM'); do
        i="$1/$i"
        rm -rd $i
    done
    for i in $(ls $1); do
        i="$1/$i"
        if [ -d "$i" ]; then
            cleanUp $i
        else
            if [[ "$i" == *".exe" ]]; then
                rm -rf $i
            fi
        fi
    done
}

cleanUp $1