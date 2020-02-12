using UnityEngine;

public class CameraController : MonoBehaviour {
    public GameObject player;
    private Vector3 m_offset;

	void Start() 
	{
        m_offset = transform.position - player.transform.position;
	}
	
	void LateUpdate()
	{
        transform.position = player.transform.position + m_offset;
	}
}
