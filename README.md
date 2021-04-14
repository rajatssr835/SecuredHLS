# SecuredHLS
1) 3bitSbox.c - Secured HLS C-code of 3 bit Sbox
2) domand.c - Secured HLS C-code of DOM AND 
3) katan32wp.c - secured HLS C-code of KATAN
4) primetime_px.out - sample power trace file as dumped by Synopsys Primetime-PX

Once traces are collected follow the below steps:
1) Convert PT-PX output to csv using ptpxout_to_csv.py
2) Evaluate TVLA using tvla.py
3) Plot TVLA using plottvla.py
