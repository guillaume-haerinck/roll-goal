using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Timer : MonoBehaviour
{

    public Text TimerText;
    public Text UIText;
    public float TimeLimit;

    private float theTimer;

    void Start()
    {
        theTimer = TimeLimit;
    }

    void Update()
    {
        theTimer -= Time.deltaTime;

        if (theTimer > 0f)
        {
            TimerText.text = theTimer.ToString("00.00");
        }
        
        if (theTimer <= 0f)
        {
            TimerText.text = "00.00";
            UIText.text = "Temps écoulé";
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
