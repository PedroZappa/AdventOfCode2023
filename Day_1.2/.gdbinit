define main
	display read_vals
	display line
	display n_lines
	display vals_list
	display vals_list[i]
	display fd
	display i
end

define gcv
	display calib_val
end

## Run at startup
set trace-commands on
set logging on
fs cmd
break 56
# run
start
main

