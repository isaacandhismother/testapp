# Description:

This is an old project which was inspired by games such as The Binding Of Isaac and Factorio. </br>
Originally made in python with some perlin noise world generation, savestate saving and loading, block placing and inventory, </br>
but was abandoned due to performance issues, so I decided to remake it in the more well optimised for games language, C++. </br>
Now this prototype has no, future, I guess, because I've lost the whole motivation and the lack of ideas. </br>

Hope somebody can see hope in this project, will take notes and Ideas I've implemented here and makes it great.

# Features:
So basically there is nothing specific to look at, but even though it has some cool features: </br>
## 1. Menu system with bindable buttons.

Menus work here by rendering the last element of the menulsist, and buttons just add a new menu into a menulist or remove the last, pretty
simple and effective way of keeping sequence of menus opened and navigating through them. What need to be reworked though is a element
editing syntax, I still can't make something easy and comfortable, but tried to make something similar to CSS. There is also no plane text lable
placement, only menu with the background and buttons with text.

## 2. 2D tile based world system divided by chunks.

Basically Rendering in the program work by the principle "render what is visible", but it still needs a rework and will probably be </br>
changed to a more efficient chunk loading-on-the-way principle, so the chunks that are visible should be loaded and saved only in case
if something is changed in it, e.g. if a player places a block or puts an item in the chest and etc., plus chunks that are needed to be
updated will stay in the memory, when other chunks will not be rendered.

## 3. Binary save-load functions that allow more efficient world saving.

My best part of the project probably was the moment I realised that data can be stored in binary, I could never imagine that the raw bites
could be written in the file in the simpliest way (not that simple actually). Okay, there may be some trouble with saving string and vector data
and the binary was not actually designed to be human readable, but it takes way less space than, lets say, json type file, like I made in the
python version of the program and, I hope, is much faster to read. So about the saving principle, basically what the program does, for saving
the chunks at the moment, it creates or opens a file named "chunk" + "row_of_the_chunk_" + "_" + "coulumn_of_the_chunk" and writes all the data into it, EVERY SINGLE
TILE OF EVERY SINGLE LAYER, and BOom we got a complete chunk file which can be loaded. And loading is some more complex process, actually we not only read the number
values that are written in it and assign to integers of short or whatewer, we also resize the string in order to read the letters of it, plus vector should be filled
with reading its previous size and then using for loop pushing back every element.</br>
