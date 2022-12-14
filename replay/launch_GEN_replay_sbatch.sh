#!/bin/bash

runnum=$1
startsegments=$2
maxsegments=$3



for ((i=$startsegments; i<=$maxsegments; i++ ))
do

    FILE=/cache/halla/sbs/GEnII/raw/e1209016_${runnum}.evio.0.${i}
    #FILE=/volatile/halla/sbs/jeffas/GMN_root/raw/e1209016_${runnum}.evio.0.${i}

    if [ ! -f $FILE ]; then
        continue;
    fi

   fnameout_pattern='/farm_out/jeffas/gen_replayed_'$runnum'_segment'$i'.out'
   sbatch --output=$fnameout_pattern run_GEN_sbatch.csh $runnum -1 0 e1209016 $i 1
   #sbatch --output=$fnameout_pattern run_GMN_sbatch.csh $runnum 200000 0 e1209016 $i 1
   #run_GEN_sbatch.csh $runnum 1000 0 e1209016 $i 1
   
   
done


