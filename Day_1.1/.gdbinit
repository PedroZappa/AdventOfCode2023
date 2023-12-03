define main
	display /d *read_vals
	display line
	display n_lines
	display /d vals_list
	display /d *vals_list
	display /d vals_list[i]
	display fd
	display /d i
end

define gcv
	display /d calib_val
	display line
	display /c *line
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

## Run at startup
set trace-commands on
set logging on
fs cmd
break 50
# break is_strnum
run
main
# strnum
