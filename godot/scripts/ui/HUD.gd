extends Control

signal game_over

onready var timerLabel = get_node("TimerLabel")
var remainingTime

func _on_Timer_timeout():
	emit_signal("game_over")

func _on_Second_timeout():
	remainingTime -= 1
	timerLabel.text = str(remainingTime)

func _ready():
	reset()
	
func reset():
	$Timer.start()
	remainingTime = $Timer.wait_time
	timerLabel.text = str(remainingTime)
