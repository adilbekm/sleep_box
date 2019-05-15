# Sleep Box #

![Sleep box][img1] ![Sleep box upside down][img2]

This is a version of **Sleep Box** as posted by [Mark Zuckerberg](https://www.facebook.com/zuck) on April 27, 2019 on Facebook. 

## How Does It Work? ##

This sleep box works the same way Mark described in his post with a couple additional functions I added myself. It emits a faint light at a time that you designate and stays lit for 1 hour. For example, if you set it to 6am, it activates at that time and stays lit until 7am.

When it is activated, it lights up smoothly starting at tiny intensity and reaching stable intensity a few minutes later. This should be helpful if you are sensative to light or sleep in a very dark room.

There is also a demo mode. Once you activate the demo mode, the sleep box lights up and down for about a minute. This is useful if you want to see what the sleep box looks like when it is lit.

## How Do I Use It? ##

There is only 1 button. You can see it when you remove the outer box: 

![Sleep box with outer box removed][img3]

You press this button as many times as the number of hours from now that you want the sleep box to activate. For example, if it's 10pm now and you want the sleep box to activate at 6am, then you press the button 8 times. When done pressing, the box will blink as many times as you pressed it so you can be sure it was set as you needed. Once set, the sleep box will activate at the set time every day, until you reset it or until the battery dies.

#### Demo Mode ####

If you press the button only once, it will go into demo mode. In demo mode, the sleep box lights up and down for about a minute. 

Notice, because a single press triggers the demo mode, you can't set the box to activate in 1 hour. So the earliest you can set it to is 2 hours (with 2 button presses). Also, the demo mode resets any previous setting so you will need to set the sleep box again.

#### Does the Sleep Box Have a Clock? ####

No, this sleep box doesn't have a clock or any other display. I tried to keep the design simple. It would also defeat the purpose to have a visible clock because Mark created it to avoid looking at the clock.

Also notice that there isn't an RTC module to keep track of time. 

## How Can I Make One? ##

Follow these steps if you would like to make this sleep box yourself. 

### 1. Get the Parts ###

1. Arduino Nano microcontroller ($22)
2. Solid oak board 4" x 3' ($10)
3. Four LEDs ($5)
4. Push button ($2)
5. 9V battery ($3)

You will also need some wires, glue, and tools like a soldering iron and sand paper.

### 2. Make the Outer Structure ###

Making the outer box is straightforward. It's made of a top piece and 4 side pieces glued together as follows:

![Outer structure][img4]

### 3. Make the Inner Structure ###

The inner structure is made of 7 pieces glued together as follows:

![Inner structure][img5]

I did not mention the center piece in **Get the Parts**. It can be made of any scrap pieace of wood (oak works great) that you might have, but if you don't then include it in your shopping list.

### 4. Assemble the Electronics ###

Connect the electronics as follows:

![Circuit diagram][img6]

Then attach everything to the inner structure as shown in a previous picture. You will need to glue the LEDs to the center piece or use a sticky material like I did. The battery and the Arduino should fit tightly in the lower compartment without a glue. 

### 5. Upload the Software ###

Upload the code from "sketch_sleepbox.c" into the Arduino unit by connecting the unit to a computer and using the Arduino IDE (the browser version works great) to make the upload.

And you are done.

[img1]: images/img_01s.jpg
[img2]: images/img_02s.jpg
[img3]: images/img_03s.jpg
[img4]: images/img_07.png
[img5]: images/img_04s.png
[img6]: images/img_05s.png
