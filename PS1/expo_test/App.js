import React, { useState } from 'react';
import { StyleSheet, Text, View, Button } from 'react-native';



export default function App() {
  const [counter, setCounter] = useState(0)
  const handleCounter = () => setCounter(counter + 1)

  return (
    <View style={styles.container}>
      <Text>your number is {counter}</Text>
      <Button onPress={handleCounter} title="click once again"></Button>
    </View>
  )
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
