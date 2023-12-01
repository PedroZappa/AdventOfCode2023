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
	display /d calib_val->first_dig
	display /d calib_val->last_dig
	display /d calib_val->calib_val

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
