extends Spatial

signal game_over
signal win


func _on_Board_touched_ground():
	emit_signal("game_over")


func _on_End_trigger_entered():
	emit_signal("win")
