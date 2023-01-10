Today i tinkered around with the Radiocommand AT9S and the receiver R9DS.
Calibrating the controller and retrieving data from the receiver was trivial, the hard part was optimising the code to be faster, as the pulseIn() function has a built-in timeout that slows everything down.
So i used the oscilloscope to try and get the timings of signal update on the different channels. I was unsuccesful as the receiver is to modern to use this kind of old school method.
Instead i read the datasheet of the receiver and found out that i can get a serial SBUS connection and get the data from there. I will be attempting it during the week. 
In case this fails(unlikely), i also thought of using a 74 series multiplexer to switch electronicaly between automated arduino control and manual control mode.  
