.name "kernel"
.comment "com" 

label:
ld %1,r3
live %1
live %:label
ld:
ld 0, r4

#TEST# COMMENT
label1:
live %4 #coment#
live  %:label1 ;coment; %4
