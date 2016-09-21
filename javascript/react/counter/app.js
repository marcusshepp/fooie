import React from 'react';
import ReactDOM from 'react-dom';


const counter = 0;


class Subtract extends React.Component {

    click_subtract(){
       console.log("clicked"); 
    }

    render(){
        return (
            <button onClick={ this.click_subtract.bind(this) }>--</button>
        );
    }

}


class Count extends React.Component {

    render(){
        return (<p>123</p>);
    }

}


class Add extends React.Component {

    click_add(){
        console.log("adding");
    }

    render(){
        return (
            <button onClick={ this.click_add.bind(this) }>++</button>
        );
    }

}


class App extends React.Component {

	render() {
		return (
            <div>
                <Add />
                <Count />
                <Subtract />
            </div>
        );
	}

}


ReactDOM.render(<App />, document.getElementById('app'));
