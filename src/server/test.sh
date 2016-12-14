#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <PORT>"
    exit 2
fi

HOST=http://localhost
PORT=$1

function try {
    local METHOD=$1
    local QUERY=$2
    local DATA=$3
    local RESULT=$4
    if [ ! -z "$DATA" ]; then
        COMMAND="-X $METHOD --data $DATA $HOST:$PORT/$QUERY"
    else
        COMMAND="-X $METHOD $HOST:$PORT/$QUERY"
    fi
    echo -e "\e[32mcurl $COMMAND\e[39m"
    OUT=$(curl -s $COMMAND)
    ret=$?
    if [ $ret != 0 ]; then
        echo "Erreur $ret"
        exit 2
    fi
    echo "$OUT"
    OUT=$(echo $OUT|tr -d '\n'|sed 's/ //g')
    if [ "$RESULT" != "$OUT" ]; then
        echo "Erreur: Mauvaise valeur de retour"
        echo "Valeur attendue: $RESULT"
        echo "Valeur obtenue:  $OUT"
        exit 2
    fi
}

try GET version '' '{"major":1,"minor":0}'
try GET user/1 '' '{"age":23,"name":"Paul"}'
try POST user/1 '{"age":24}'
try GET user/1 '' '{"age":24,"name":"Paul"}'
try PUT user '{"name":"Jean","age":44}' '{"id":2}'
try GET user/2 '' '{"age":44,"name":"Jean"}'
try DELETE user/2
try GET user/2 '' 'Invaliduserid'

