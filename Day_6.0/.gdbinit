define main
	display time
	display /d time_num
	display /d distance
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
end


### Startup Commands
set logging on
set trace-commands on
fs cmd

break main
run
main

# break get_time
# run
# get_time

# break get_distance
# run
# get_distance
