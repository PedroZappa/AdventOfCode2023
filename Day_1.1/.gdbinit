define main
	display /d *read_vals
	display line
	display n_lines
	display vals_list
	display /d vals_list[i]
	display fd
	display i
end

define gcv
	display /d calib_val
	display line
end

define strnum
display line
	display n_strs
	display numstr[i]
	display i
end

define strtoi
	display str
end

## Run at startup
set trace-commands on
set logging on
fs cmd
break 50
run
main
