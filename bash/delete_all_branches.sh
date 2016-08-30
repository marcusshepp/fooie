all_branches=$(git branch)
arr_of_branches=(`echo ${all_branches}`)
for i in "${arr_of_branches[@]}"
do 
    # don't delete master
    # would git even let me?
    if [ $i != "master" ];
    then
        echo "deleting branch: $i"
        git branch -D $i
    fi
done