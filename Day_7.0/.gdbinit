define main
	display /d hands[0]
	display /d hands[1]
	display /d hands[2]
	display /d hands[3]
	display /d hands[4]
	display /d bids[0]
	display /d bids[1]
	display /d bids[2]
	display /d bids[3]
	display /d bids[4]
	display /d winnings[0]
	display /d winnings[1]
	display /d winnings[2]
	display /d winnings[3]
	display /d winnings[4]
	display line
	display /d fd
	display /d i
end

define parse_line
	display line
	display hand
	display bid
	display /d hand
	display /d bid
end

define get_hand
	display hand
	display hand[i]
	display /d i
end


### Debugger Startup ###
set logging enabled on
set trace-commands on
fs cmd

# Start on top o'main
# start
# main

# Start at get_hand
break 33
run
main
step
parse_line
step
get_hand
