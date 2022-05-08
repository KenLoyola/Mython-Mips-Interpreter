#!/bin/sh
# to run this script: 
#   - make sure you have the executable p4_c
#   - run with "./test.sh TEST_CASE_NUM"
#   - e.g. "./test.sh 0"
INPUTDIR=../tests/input
OUTPUTDIR=./output
EXPECTEDDIR=../tests/output_expected
MARS=../tests/Mars4_5.jar
echo "Test with test$1.my:"
echo "-------------------------------------------------------------"
echo " - Use your compiler to generate MIPS translation test$1.s"
echo "-------------------------------------------------------------"
./p4_c <$INPUTDIR/test$1.my >$OUTPUTDIR/test$1.s

echo "-------------------------------------------------------------"
echo " - Verify generated MIPS assembles "
echo "   and runs with expected behavior "
echo "-------------------------------------------------------------"
echo "Running MIPS code your compiler generated ($OUTPUTDIR/test$1.s):"
java -jar $MARS sm $OUTPUTDIR/test$1.s 

echo "-------------------------------------------------------------"
echo "Running MIPS code from provided example ($EXPECTEDDIR/test$1.s):"
java -jar $MARS sm $EXPECTEDDIR/test$1.s 

# rm -f $OUTPUTDIR/test$1.s 
# generated .s file will be removed if you uncomment the line above 
