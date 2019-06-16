using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;
using UnityEngine.SceneManagement;

public class BallController : MonoBehaviour {

    public Text UIText;
    public float speed;
    public float velocityTime;

    private Rigidbody rb;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    void FixedUpdate()
    {
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(-moveHorizontal, 0.0f, -moveVertical);

        rb.AddForce(movement * speed, ForceMode.VelocityChange); ;
        rb.velocity *= velocityTime; 
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Finish"))
        {
            UIText.text = "Gagne";
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
        if (other.gameObject.CompareTag("Respawn"))
        {
            UIText.text = "Perdu";
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
