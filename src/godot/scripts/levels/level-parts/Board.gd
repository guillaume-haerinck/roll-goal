extends Spatial

signal touched_ground

func _on_GroundTrigger_body_entered(body):
	emit_signal("touched_ground")
