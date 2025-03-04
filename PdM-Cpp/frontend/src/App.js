import React, { useEffect, useState } from 'react';
import axios from 'axios';

function App() {
  const [data, setData] = useState(null);

  // Assume your backend exposes a REST endpoint at /status on port 8080
  useEffect(() => {
    axios.get('http://backend:8080/status')
      .then(response => setData(response.data))
      .catch(error => console.error('Error fetching backend data:', error));
  }, []);

  return (
    <div>
      <h1>Predictive Maintenance Dashboard</h1>
      { data ? (
          <div>
            <h2>Status:</h2>
            <pre>{JSON.stringify(data, null, 2)}</pre>
          </div>
        ) : (
          <p>Loading data...</p>
        )
      }
    </div>
  );
}

export default App;
