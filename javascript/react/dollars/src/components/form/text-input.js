import React from 'react';

import Input from './input';

export default class TextInput extends React.Component {
	render() {
		return (
			<Input 
				name={ this.props.name }
				label_text={ this.props.label_text }
				include_label={ true }
				type='text' />
		);
	}
}
