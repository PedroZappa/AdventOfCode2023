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
	display line
	display line[i]
	display hand
	display hand[i]
	display /d i
end

define sort
	display arr
	display *arr
	display *arr[0]
	display **arr
	display arr[i][j]
	display arr[i][j+1]
	display arr[i+1][j]
	display /d n
	display /d i
	display /d j
	display /d check_card
end

define compare_cards
	display hand_a
	display hand_b
	display /d card_a
	display /d card_b
	display /d card_pow[n]
	display /d i
	display /d a_value
	display /d b_value
	display /d n
end



# Start on top o'main
# start
# main

# Start at get_hand
# break 33
# run
# main
# step
# parse_line
# step
# get_hand

#Start at bubble_sort
# break 48
# run
# main
# step
# sort

# Start sort
break 114
run
sort
refresh


### Options ###
set logging enabled
set trace-commands
set print array
set print pretty
