# Sleep Box #

![Sleep box][img1] ![Sleep box upside down][img2]

This is my version of a **sleep box** that [Mark Zuckerberg](https://www.facebook.com/zuck) created and posted on Facebook on April 27, 2019.

## What is It? ##

The Facebook founder invented a box to help his wife sleep better through the night. Priscilla was having a hard time falling back asleep after checking the time in the middle of the night to see if the kids might wake up soon, so he created what he called a "sleep box" as a way to tell if it was a good time to wake up without having to actually check the time. (I think most people would agree that checking the time during the night *is* stressful)

## How Does It Work? ##

This sleep box works the same way Mark described in his post with a couple additional functions I added myself. It emits a faint light at a time you specify and stays lit for 1 hour. For example, if you set it to 6am, it will light up at that time and stay lit until 7am. 

When it is activated, it lights up smoothly starting at tiny intensity and reaching stable intensity a few minutes later. This might be helpful if you are sensitive to light or sleep in a very dark room.

There is also a demo mode. Once you activate the demo mode, the sleep box lights up and down a few times for about a minute. This is useful if you want to see what the sleep box looks like when lit.

## How Do I Use It? ##

There is only 1 button. You can see it when you remove the outer box:

![Sleep box with outer box removed][img3]

You can press this button as many times as the number of hours from now that you want the sleep box to activate. For example, if it's 10pm now and you want the sleep box to activate at 6am, then you press the button 8 times. When done pressing, the box will blink as many times as you pressed it so you can be sure it was set as you wanted. Once set, the sleep box will activate at the designated time every day, until you reset it or until the battery dies.

#### Demo Mode ####

If you press the button only once, it will go into demo mode. In demo mode, the sleep box lights up and down for about a minute.

Notice, because a single press triggers the demo mode, you can't set the box to activate in 1 hour. The earliest you can set it to is 2 hours (with 2 button presses). Also, the demo mode resets any previous setting so you will need to set the sleep box again.

#### Does the Sleep Box Have a Clock? ####

No, this sleep box doesn't have a clock or any other display. I tried to keep the design simple. It would also defeat the purpose to have a visible clock because Mark created it to avoid looking at the clock.

Also notice that there isn't an RTC module to keep track of the real time. It's based on simple counting - see the code in file "sketch_sleepbox.c".

## How Can I Make One? ##

Follow these steps if you would like to make this sleep box yourself. 

### 1. Get the parts ###

1. Arduino Nano microcontroller ($22)
2. Solid oak board 4" x 3' ($10)
3. Four LEDs ($5)
4. Push button ($2)
5. 9V battery ($3)

You will also need some wires, glue, and tools like soldering iron and sand paper.

### 2. Make the outer structure ###

Making the outer box is straightforward. It's made of a top piece and 4 side pieces glued together as follows:

![Outer structure][img4]

### 3. Make the inner structure ###

The inner structure is made of 7 pieces glued together as shown here:

![Inner structure][img5]

(I did not mention the center piece in Get the parts. It can be made of any scrap piece of wood you might have (oak works great). But if you don't have any, then include it in your shopping list)

### 4. Assemble the Electronics ###

Connect the electronics as follows:

![Circuit diagram][img6]

Then attach everything to the inner structure as shown in one of the previous pictures. You will need to glue the LEDs to the center piece or use tape or some sticky material. The battery and the Arduino unit should fit tightly in the lower compartment without glue.

### 5. Upload the Software ###

Finally, upload the C code in file "sketch_sleepbox.c" into the Arduino unit by connecting the unit to a PC and using the Arduino IDE to complete the upload.

And you are done.

[img1]: images/github_01.jpg
[img2]: images/github_02.jpg
[img3]: images/github_03.jpg
[img4]: images/github_04.png
[img5]: images/github_05.png
[img6]: images/github_06.png
