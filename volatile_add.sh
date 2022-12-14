#!/bin/bash

runnum=$1
first_seg=$2
last_seg=$3

export DIR=/lustre19/expphy/volatile/halla/sbs/jeffas/GEN_root/Rootfiles
#export OUT_FILE=gmn_replayed_${runnum}_stream0_seg${first_seg}_${last_seg}.root
export OUT_FILE=gen_replayed_${runnum}_all.root

cd $DIR

export cmd=""

for ((i=$first_seg; i<=$last_seg; i++ ))
do

    FILE=e1209016_fullreplay_${runnum}_stream0_2_seg${i}_${i}.root
    #FILE=e1209016_replayed_${runnum}_stream0_seg${i}_${i}_firstevent0_nevent200000.root

    if [ ! -f $FILE ]; then
        continue;
    fi

cmd=$cmd" e1209016_fullreplay_"$runnum"_stream0_2_seg"$i"_"$i".root"
#cmd=$cmd" e1209016_replayed_"$runnum"_stream0_seg"$i"_"$i"_firstevent0_nevent200000.root"

done

hadd -k -f $OUT_FILE $cmd
