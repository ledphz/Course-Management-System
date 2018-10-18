#!/bin/bash
cd ../log
tar czvf mylog.tar log.log
mv mylog.tar  ../mylog

cd ../mylog
tar zxvf mylog.tar
rm mylog.tar
cd ../BUILD
