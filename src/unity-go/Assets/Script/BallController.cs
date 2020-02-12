using UnityEngine.UI;
using UnityEngine;
using UnityEngine.SceneManagement;

public class BallController : MonoBehaviour {

    public Text UIText;
    public float speed;
    public float velocityAttenuation;
    private Rigidbody m_rb;

    void Start()
    {
        m_rb = GetComponent<Rigidbody>();
    }

    void FixedUpdate()
    {
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");
        Vector3 movement = new Vector3(-moveHorizontal, 0.0f, -moveVertical);

        m_rb.AddForce(movement * speed, ForceMode.VelocityChange);
        m_rb.velocity *= velocityAttenuation;
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Finish"))
        {
            UIText.text = "Won";
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        } 
        else if (other.gameObject.CompareTag("Respawn"))
        {
            UIText.text = "Lost";
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
