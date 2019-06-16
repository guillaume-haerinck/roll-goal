extends StaticBody

signal trigger_entered

func _on_EndTrigger_body_entered(body):
	emit_signal("trigger_entered")
