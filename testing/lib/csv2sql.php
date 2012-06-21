#!/usr/bin/env php
<?php

$filename = $argv[1];

$file_handle = fopen($filename, 'r');

if ($file_handle === false) {
   die('could not open file');
}

$line = fgets($file_handle);

$fieldNames = explode(',', trim($line, "\n"));

$timeStamp = array_search('timeStamp', $fieldNames);
$elapsed = array_search('elapsed', $fieldNames);
$label = array_search('label', $fieldNames);
$responseCode = array_search('responseCode', $fieldNames);
$responseMessage = array_search('responseMessage', $fieldNames);
$threadName = array_search('threadName', $fieldNames);
$dataType = array_search('dataType', $fieldNames);
$success = array_search('success', $fieldNames);
$bytes = array_search('bytes', $fieldNames);
$Latency = array_search('Latency', $fieldNames);

echo "INSERT INTO tests (description, executed) VALUES ('".$filename."', NOW());";
echo "SET @ID = LAST_INSERT_ID();";

$i = 0;
while (!feof($file_handle)) {
   $line = fgets($file_handle);
   $data = explode(',', trim($line, "\n"));
   if(strlen($line) > 0) {
       if(intval($data[$elapsed]) >= 0) {
           if($i % 1000 == 0) {
               echo ";\n\nINSERT INTO results VALUES ";
           } else if ($i != 0) {
               echo ',';
           }
           echo '(NULL, @ID, '.($i+1).', FROM_UNIXTIME(ROUND('.$data[$timeStamp].
               '/1000)), '.$data[$elapsed].", '".$data[$label]."', '".$data[$responseCode]."', '".
               $data[$responseMessage]."', '".$data[$threadName]."', '".$data[$dataType].
               "', ('".$data[$success]."' = 'true'), ".$data[$bytes].', '.$data[$Latency].")\n";
       }
   }
   $i++;
}

fclose($file_handle);
