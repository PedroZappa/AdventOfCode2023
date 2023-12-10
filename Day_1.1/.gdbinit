define main
	display /d *read_vals
	display line
	display n_lines
	display vals_list
	display *vals_list
	display /d vals_list[i]
	display fd
	display /d i
end

define gcv
	display got_first
	display /d calib_val->first_dig
	display /d calib_val->last_dig
	display /d calib_val->calib_val
	display line
	display /c *line
end

define getnum
	display line
	display calib_val
	display /d calib_val->first_dig
	display /d calib_val->last_dig
	display /d *got_first
	display /d got_last
end

define strnum
	display line
	display /d slen
	display /d n_strs
	display numstr[i]
	display /d i
	display /d num
	display /d skip
end

define getskip
	display line
	display numstr[i]
	display /d n_strs
	display /d slen
	display /d num
	display /d i
	display /d skip
end

define numstrlen
	display num
	display len
	display *numstr
	display numstrs[num] 
end

define strtoi
	display str
end

define vgdb
	target remote | vgdb
end

define mchk
	monitor leak_check full reachable any
end

## Run at startup
set trace-commands on
set logging on
fs cmd

# break main
break 51
# break main if line == "abcone2threexyz"
run
main

# break getnum
# run
# getnum

# break is_strnum
# run
# strnum
