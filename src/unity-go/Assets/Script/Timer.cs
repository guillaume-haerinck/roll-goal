using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Timer : MonoBehaviour
{
    public Text timerText;
    public Text uiText;
    public float timeLimit;
    private float m_timer;

    void Start()
    {
        m_timer = timeLimit;
    }

    void Update()
    {
        m_timer -= Time.deltaTime;

        if (m_timer > 0f)
        {
            timerText.text = m_timer.ToString("00.00");
        }
        else
        {
            timerText.text = "00.00";
            uiText.text = "Temps écoulé";
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
