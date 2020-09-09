# Map-aligner

This assignment was the final exam of the C++ course at faculty of informatik in 2020 spring semester at the Eötvös Loránd University. The main file contains the 
description of the task and a test code for checking the functions in the header file.

### The description of the task:

The map_aligner is a class template, which collects std::map's 
 with the add function or the operator+= . The template parameters of the map_aligner
 describe the template parameters of the maps. The align() function align the 
 collected maps: every map will have all the items, which apeared in 
 any of the collected maps.
 In default, the align() will give the default constructed value for the 
 keys which weren't in the map before.
 The set_filler function can overwrite this value. 
 The count() returns the number of alligned maps.
 It's not secessary to sort by the default sort operation.
 There is an erease operation: if the type of a key and value pair are different,
 then the key must be ereased from all of the maps. However, if the type of the
 the key and value pair are the same, then it must be ereased as a key from all of the 
 maps (by sorting), or as a value (by equality test), in the later case, the items
 with this key must be ereased from all of the maps.
