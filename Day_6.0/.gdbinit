define main
	display time
	display /d time_num
	display /d distance_num
	display distance
	display /d fd
end

define get_time
	display line
	display local_line
	display /d time
	display /d fixlen
end

define get_distance
	display line
	display local_line
	display /d time
	display /d fixlen
	display /d distance
end

define get_n_ways
	display /d time
	display /d record_dist
	display /d n_ways
	display /d press_time
	display /d travel_time
	display /d travel_dist
end


### Startup Commands
set logging on
set trace-commands on
fs cmd

# break main
# run
# main

# break get_time
# run
# get_time

# debug get_distance
break 38
run
main
step
get_distance
