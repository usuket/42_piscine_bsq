#!/bin/sh

echo "CREATE MAP START for ../input/"
time perl map_maker.pl 1 1 1 > ../input/map1_1_1
time perl map_maker.pl 2 2 0 > ../input/map2_2_0
#time perl map_maker.pl 3 3 1 > ../input/map3_3_1
#time perl map_maker.pl 5 5 2 > ../input/map5_5_2
#time perl map_maker.pl 7 8 2 > ../input/map7_8_2
#time perl map_maker.pl 10 10 2 > ../input/map10_10_2
#time perl map_maker.pl 50 50 2 > ../input/map50_50_2
#time perl map_maker.pl 100 100 2 > ../input/map100_100_2
#time perl map_maker.pl 200 200 2 > ../input/map200_200_2
#time perl map_maker.pl 500 500 2 > ../input/map500_500_2
#time perl map_maker.pl 1000 1000 2 > ../input/map1000_1000_2
#time perl map_maker.pl 3000 2000 2 > ../input/map3000_2000_2
time perl map_maker.pl 5000 5000 2 > ../input/map5000_5000_2
#time perl map_maker.pl 10000 10000 2 > ../input/map10000_10000_2
echo "CREATE MAP DONE"
