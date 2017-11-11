The OpenETU is an open source electronic trigger unit for V2 airsoft gearboxes. It is simply a controller board that can control a single mosfet. It may be simple, but it brings a few very cool features (in theory) to the table...

•	Easily tunable trigger without having to re-disassemble (...yeap) … the gear box 

•	Programmable fire modes (no fancy smancy trigger based programming yet) 

•	Runaway firing safety cutoff (if something goes wrong it will never fire for more than 5 secs if the trigger is let go. 

•	No chance for semi auto lock (the gearbox always completes one cycle). 

I am not a professional circuit designer, nor a code guru by any stretch of the imagination, this project is a means for me to learn and get something that I find useful out of it and I hope maybe others will as well. 

I will also be developing a Bluetooth version. It will be based on either the Espressif esp32 or SiLabs BGM121(whichever is easier/cheaper to source and program. This version really opens up the possibilities (in my head anyway).

•	Tunable trigger right from your phone (easily set trigger pull distance from the app, which sucks btw)

•	Choose between fire modes (full auto and burst plus…how many rounds of burst do you want?)

•	Battery voltage level in app (Really not much more than that  say).

•	Semi lock mode. DMR shooting to hot? I know I am. Create a bond of trust with the ref by letting him/her semi lock your gun for the day! Try to defeat it by pulling your battery and it just resets the internal timer so that it never overcomes the interval variable! (Don’t worry it will eventually unlock when you reconnect to the app and the timer is at zero) ...there’s probably some way to defeat it I’m sure… 

•	All this and maybe more (but probably not), if I can actually learn java and app design…otherwise it will just be the crappy MIT Inventor app with basic features…

