import React from 'react';
import ReactDOM from 'react-dom';


var counter = 0;


class Subtract extends React.Component {
    render(){
        return (
            <button onClick={ this.props.click_subtract.bind(this) }>--</button>
        );
    }
}


class Count extends React.Component {
    render(){
        return (<p>{this.props.count}</p>);
    }
}


class Add extends React.Component {
    render(){
        return (
            <button onClick={ this.props.click_add.bind(this) }>++</button>
        );
    }
}


class App extends React.Component {

    constructor(props){
        super(props);
        this.state = { counter: counter };
    }
    click_subtract(){
        var new_count = this.state.counter - 1;
        this.setState({ counter: new_count });
        console.log(this.state.counter);
    }
    click_add(){
        console.log("adding");
    }
	render() {
		return (
            <div>
                <Add click_add={ this.click_add }/>
                <Count count={ this.state.counter }/>
                <Subtract click_subtract={ this.click_subtract } />
            </div>
        );
	}

}


ReactDOM.render(<App />, document.getElementById('app'));
